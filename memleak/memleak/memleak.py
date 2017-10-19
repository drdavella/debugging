from os.path import basename
from sys import stderr, argv
import _memleak


def main():
    if len(argv) != 2:
        progname = basename(argv[0])
        stderr.write(f"usage: {progname} <size>\n")
        return 1

    _memleak.allocate(int(argv[1]))


if __name__ == '__main__':
    main()
