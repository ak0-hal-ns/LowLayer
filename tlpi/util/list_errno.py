import os
import re
from collections import defaultdict


DIRNAME = "/usr/include/asm-generic/"
FNAME1 = "errno-base.h"
FNAME2 = "errno.h"


def gen_deferr(fname, dirname=DIRNAME):
    with open(os.path.join(dirname, fname)) as fp:
        for line in fp:
            line = re.sub(r'/\*.*\*/', '', line).rstrip()
            try:
                _, ename, errno = line.split()
            except ValueError:
                pass
            else:
                yield ename, errno


def create_errdict(fnames):
    name2no = {}
    no2name = defaultdict(list)
    for fname in fnames:
        for ename, errno in gen_deferr(fname):
            try:
                name2no[ename] = int(errno)
            except ValueError:
                errno = name2no[errno]
                name2no[ename] = int(errno)
            finally:
                no2name[int(errno)].append(ename)
    return no2name


def main(fnames):
    errdict = create_errdict(fnames)
    s = ['static char *ename[] = {',
         '    /*   0 */    "",']
    for errno, ename in sorted(errdict.items()):
        s.append(f'    /* {errno:3d} */    "{"/".join(ename):s}",')
    else:
        s.append('};')
        s.append('')
        s.append(f'#define MAX_ENAME {errno:d}')
    return '\n'.join(s)


if __name__ == '__main__':
    s = main([FNAME1, FNAME2])
    print(s)
