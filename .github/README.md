# Caliginousoft Connect

This is a simple cross-platform connect game. The intent of this is to mostly brush up on my C++. However, I also will be iterating on this program over time as a demonstration to potential employers of my abilities.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine.

### Prerequisites

The code includes file for building with [Buck](https://buckbuild.com/ "Buck's Website"). If you want to utilize the build files included in the project, you'll need to have it installed for your platform(s).

Additionally, if you are attempting to build the windows version, you will need to use a command prompt that has all of the developer environment variables set or else manually provide the compiler and linker with all of the relevant paths on your system (I am using a .buckconfig.local file to store my paths just so I don't have to use a non-standard console).

Regardless of whether or not you are using Buck, you will need a c\++17 compatible compiler and linker. Project is currently building in development with:
Linux: g++ 5.5.0
Windows: VisualStudio 2017 Community (Compiler version 19.14.26428.1, Linker version 14.14.26428.1)

### Building with Buck

I have provided aliases to use when building the project with Buck for convenience. Simply do:

Linux:
```
buck build connect-linux
```

Windows:
```
buck build connect-windows
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) and [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) for details on our code of conduct, and the process for submitting pull requests.

## Versioning

[SemVer](http://semver.org/) is used for versioning. For the versions available, see the [tags on this repository](https://github.com/jgadrow/connect/tags).

## Authors

* **Jim C. Gadrow** - *Initial work* - Caliginousoft

See also the list of [contributors](https://github.com/jgadrow/connect/contributors) who participated in this project.

## License

This project, like all Caliginousoft software, is licensed under the Unlicense as a public domain contribution - see the [UNLICENSE.md](UNLICENSE.md) file for details

## Acknowledgments

* Observer subject class derived from [Juan's C++ Blog](https://juanchopanzacpp.wordpress.com/2013/02/24/simple-observer-pattern-implementation-c11/).
