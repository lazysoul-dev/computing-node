const Benchmark = require('benchmark')
const { estimatePiNumber } = require('../index.js')

function pureEstimatePiNumber(points) {
  let i = points
  let inside = 0

  while (i-- > 0) {
    let x = Math.random()
    let y = Math.random()

    if ((x * x) + (y * y) <= 1) {
      inside++
    }
  }

  return (inside / points) * 4
}

const main = () => {
  const CHECK_NUMBER = 6000

  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Вычисление числа Пи', () => {
      pureEstimatePiNumber(CHECK_NUMBER)
    })
    .add('NaN Вычисление числа Пи      ', () => {
      estimatePiNumber(CHECK_NUMBER)
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
