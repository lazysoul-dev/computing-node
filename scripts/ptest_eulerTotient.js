const Benchmark = require('benchmark')
const { eulerTotient } = require('../index.js')

function gcd(a, b) {
  if (a === 0) {
    return b
  }

  return gcd(b % a, a)
}

function pureEulerTotient(n) {
  let result = 1

  for (let i = 2; i < n; i++) {
    if (gcd(i, n) === 1) {
      result++
    }
  }

  return result
}

const main = () => {
  const CHECK_NUMBER = 10000

  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Тотиет Эйлера (10000)', () => {
      eulerTotient(CHECK_NUMBER)
    })
    .add('NaN Тотиет Эйлера (10000)      ', () => {
      pureEulerTotient(CHECK_NUMBER)
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
