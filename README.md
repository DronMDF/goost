Pure object oriented gost ciphers implementation

![Build](https://github.com/DronMDF/goost/workflows/Build/badge.svg)
[![Coverage](https://codecov.io/gh/DronMDF/goost/branch/master/graph/badge.svg)](https://codecov.io/gh/DronMDF/goost)
[ ![Download](https://api.bintray.com/packages/mdf/pureoop/goost%3Adronmdf/images/download.svg) ](https://bintray.com/mdf/pureoop/goost%3Adronmdf/_latestVersion)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/DronMDF/2out/blob/master/LICENSE)

# Standarts

[GOST 28147-89](http://gostexpert.ru/data/files/28147-89/6b481f48474c8bdcbe030a95778c5292.pdf)

[GOST 34.12-2015 Block ciphers](https://tc26.ru/standard/gost/GOST_R_3412-2015.pdf)

[GOST 34.13-2015 Modes of operation for block ciphers](https://tc26.ru/standard/gost/GOST_R_3413-2015.pdf)

# Principles of the project

* No code in ctor
* Only one primary ctor (all other are delegating to primary)
* No static
* No null
* No new (use make_unique or make_shared)
* All classes are final
* All base classes are abstract (with default virtual dtor)
* All method are const (exclude private classes)
* All member are private and const (exclude private classes)

# Building

```sh
$ conan remote add mdf https://api.bintray.com/conan/mdf/pureoop
$ conan install <path to goost> -s compiler.libcxx='libstdc++11' --build 2out
$ cmake -GNinja <path to goost>
$ ninja
$ ninja test
```
