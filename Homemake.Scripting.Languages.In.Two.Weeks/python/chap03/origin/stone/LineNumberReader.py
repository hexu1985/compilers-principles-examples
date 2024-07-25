
class LineNumberReader:
    def __init__(self, f):  # open() -> f
        self.file = f
        self.lineNumber = 0

    def readLine(self):
        line = self.file.readline()
        if line: 
            self.lineNumber += 1
        return line

    def getLineNumber(self):
        return self.lineNumber


if __name__ == "__main__":
    with open("test.txt") as f:
        reader = LineNumberReader(f)
        while True:
            line = reader.readLine()
            if not line:
                break
            print("{}. {}".format(reader.getLineNumber(), line))
