Pure object oriented gost ciphers implementation

![Shippable test](https://api.shippable.com/projects/58a0cbe8b195740f00e03db0/badge?branch=master)

# Principles of the project

* No code in ctor
* Only one primary ctor (all other are delegating to primary)
* No static
* No null
* No new (make_unique or make_shared)
* All classes are final
* All base classes are abstract (with default virtual dtor)
* All method are const
* All member are private and const (exclude private classes)
