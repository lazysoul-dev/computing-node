const Benchmark = require('benchmark')
const { createRandomVector } = require('./_helpers.js')
const { bubbleSort } = require('../index.js')

const pureBubbleSort = providedVector => {
  const vector = [...providedVector]

  for (let i = 0; i < vector.length - 1; i++) {
    let swapped = false

    for (let j = 0; j < vector.length - i - 1; j++) {
      if (vector[j] > vector[j + 1]) {
        swapped = true
        const temp = vector[j + 1]
        vector[j + 1] = vector[j]
        vector[j] = temp
      }
    }

    if (!swapped) {
      break
    }
  }

  return vector
}

const main = () => {
  const CHECK_NUMBER = 100
  const vector = createRandomVector(CHECK_NUMBER)
  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Алгоритм Пузырьковой сортировки', () => {
      pureBubbleSort(vector)
    })
    .add('NaN Алгоритм Пузырьковой сортировки      ', () => {
      bubbleSort(vector)
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
