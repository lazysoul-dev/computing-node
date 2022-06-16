const Benchmark = require('benchmark')
const { newmanConway } = require('../index.js')

const pureNewmanConway = n => {
  if (n == 1 || n == 2) {
    return 1
  }

  return pureNewmanConway(pureNewmanConway(n - 1))
    + pureNewmanConway(n - pureNewmanConway(n - 1))
}

const main = () => {
  const CHECK_NUMBER = 14

  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Алгоритм Ньюмана-Конвея', () => {
      pureNewmanConway(CHECK_NUMBER)
    })
    .add('NaN Алгоритм Ньюмана-Конвея      ', () => {
      newmanConway(CHECK_NUMBER)
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
