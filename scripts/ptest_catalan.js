const Benchmark = require('benchmark')
const { catalan } = require('../index.js')

function pureCatalan(n) {
  if (n <= 1) {
    return 1
  }

  let res = 0

  for (let i = 0; i < n; i++) {
    res += pureCatalan(i) * pureCatalan(n - i - 1);
  }

  return res;
}

const main = () => {
  const CHECK_NUMBER = 10

  const suite = new Benchmark.Suite

  suite
    .add('Javascipt Алгоритм Каталана', () => {
      pureCatalan(CHECK_NUMBER)
    })
    .add('NaN Алгоритм Каталана      ', () => {
      catalan(CHECK_NUMBER)
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
