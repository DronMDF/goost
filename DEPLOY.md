# Deployment

Remotes should be present and logged in
```sh
$ conan remote list
mdf: https://api.bintray.com/conan/mdf/pureoop [Verify SSL: True]
$ conan user -p <APIKEY> -r mdf <USERNAME>
Changed user of remote 'mdf' from 'None' (anonymous) to 'dronmdf'
```

Note: Use APIKEY as password (look it in bintray profile)

```sh
$ conan create . dronmdf/testing
$ conan upload goost/0.3@dronmdf/testing --all -r=mdf
```
