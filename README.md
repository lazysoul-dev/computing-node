# Computing Node

Package for improving perfomance of computing tasks in Node.js

## Building

### Install node.js

```shell
$ curl -fsSL https://deb.nodesource.com/setup_17.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```

### Install node.js (EXTRA)

Install n package to work with node and npm versions.

```shell
$ sudo npm i -g n
```

Install latest node version.

```shell
$ sudo n latest
```

### Install packages for native addons

```shell
$ sudo apt-get install gcc g++ make build-essentials
```

### Install dependencies and first build

```shell
$ npm install
$ npm run configure
$ npm run build
```

## Build on change

```shell
$ npm run build
```

## Configure on binding.gyp change

```shell
$ npm run configure
$ npm run build
```

## Test

```shell
$ npm test
```

## Perfomance tests

```shell
$ npm run ptest:FUNCTION_NAME
```

Ptest list:

```shell
$ npm run ptest:fibonacci
$ npm run ptest:isPrime
$ npm run ptest:matrixSum
$ npm run ptest:sumList
```

Perfomance tests implementation in `./scripts/perfomance_test_FUNCTION_NAME.js`