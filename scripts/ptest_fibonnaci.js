const Benchmark = require('benchmark')
const { fibonacci } = require('../index.js')

const pureFibonacci = n => {
  if (n < 1) {
    return 1
  }

  return pureFibonacci(n - 1) + pureFibonacci(n - 2)
}

const main = () => {
  const CHECK_NUMBER = 20

  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Фибоначчи(20)', () => {
      pureFibonacci(CHECK_NUMBER)
    })
    .add('NaN Фибоначчи(20)      ', () => {
      fibonacci(CHECK_NUMBER)
    })
    .on('cycle', event => {
      console.log(String(event.target))
    })
    .on('complete', function () {
      console.log('\nСамый быстрый: ' + this.filter('fastest').map('name'))
    })
    .run({async: false})
}

main()
