import logging
import re
import sys
from pathlib import Path
from junit_reporter import TestCase, TestSuite, JUnitReporter

class UnityReport:
    class Result:
        def __init__(self, name, file, line, status, message):
            self.name = name
            self.file = file
            self.line = line
            self.status = status
            self.message= message
            logging.debug(f"Created Result: {self.name}, {self.file}, {self.line}, {self.status}")


    def __init__(self, stream):
        self._stream = stream
        self.results = []
        logging.debug("Initialized UnityReport")

    def parse(self):
        for line in self._stream:
            m = re.match('(.*):(\d+):(\w+):(PASS|FAIL)(:(.*))?', line)
            if m:
                file = Path(m.group(1))
                if m.group(4) == 'FAIL':
                   fail_message = f"Test failed in {file} at line {m.group(2)}: {m.group(6)}"
                result = self.Result(m.group(3), file, m.group(2), m.group(4), fail_message if m.group(4) == 'FAIL' else None)
                self.results.append(result)
                logging.debug(f"Parsed line: {line.strip()}, Result: {result.name}, {result.file}, {result.line}, {result.status}")


    def to_xunit(self):
        test_cases = []
        for result in self.results:
            test_case = TestCase(result.name, classname=str(result.file), stdout='Test passed', stderr='Test failed' if result.status == 'FAIL' else '')
            if result.status == 'FAIL':
              test_case.add_failure(output=result.message)
            test_cases.append(test_case)
            logging.debug(f"Converted Result to xunit: {result.name}, {result.file}, {result.line}, {result.status}")
        test_suite = TestSuite("Unity", test_cases)
        return JUnitReporter.report_to_string([test_suite])

def main():
    logging.basicConfig(level=logging.DEBUG)
    if len(sys.argv) < 2:
        print("Please provide a report file as a command line argument.")
        return
    report_file = sys.argv[1]
    with open(report_file, 'r') as f:
        report = UnityReport(f)
        report.parse()
        xunit = report.to_xunit()
        xunit_file = Path(report_file).with_suffix('.xml')
        with open(xunit_file, 'w') as f:
            f.write(xunit)
        print(f"junit XML report written to {xunit_file}")

if __name__ == '__main__':
    main()