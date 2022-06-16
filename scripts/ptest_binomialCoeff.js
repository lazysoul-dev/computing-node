const Benchmark = require('benchmark')
const { binomialCoeff } = require('../index.js')

function pureBinomailCoeff(n, k) {
  if (k > n) {
    return 0
  }

  if (k === 0 || k === n) {
    return 1
  }

  return pureBinomailCoeff(n - 1, k - 1) + pureBinomailCoeff(n - 1, k)
}

const main = () => {
  const CHECK_NUMBER = 135
  const CHECK_NUMBER_b = 2
  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Алгоритм Биномиального коэффициента', () => {
      pureBinomailCoeff(CHECK_NUMBER, CHECK_NUMBER_b)
    })
    .add('NaN Алгоритм Биномиального коэффициента      ', () => {
      binomialCoeff(CHECK_NUMBER, CHECK_NUMBER_b)
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
