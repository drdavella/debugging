from os.path import basename
from sys import stderr, argv
import _segfault


def main():
    if len(argv) != 3:
        progname = basename(argv[0])
        stderr.write(f"usage: {progname} <size> <num>\n")
        return 1

    size, num = [int(x) for x in argv[1:]]
    result = _segfault.do_something(size, num)
    print(f"total = {result}")


if __name__ == '__main__':
    main()
