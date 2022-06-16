const Benchmark = require('benchmark')
const { createMatrix } = require('./_helpers.js')
const { matrixSum } = require('../index.js')

const pureMatrixSum = (someMatrixA, someMatrixB) => {
  let result = []

  for (let i = 0; i < someMatrixA.length; i++) {
    result.push([])

    for (let j = 0; j < someMatrixA[i].length; j++) {
      result[i][j] = someMatrixA[i][j] + someMatrixB[i][j]
    }
  }

  return result
}

const main = () => {
  const CHECK_NUMBER = 20
  const someMatrix = createMatrix(CHECK_NUMBER)

  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Сумма матриц', () => {
      pureMatrixSum(someMatrix, someMatrix)
    })
    .add('NaN Сумма матриц      ', () => {
      matrixSum(someMatrix, someMatrix)
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
