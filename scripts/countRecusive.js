let calls = 0

function recur(n, k) {
  calls += 1
  if (k > n) {
    return 0
  }

  if (k === 0 || k === n) {
    return 1
  }

  return recur(n - 1, k - 1) + recur(n - 1, k)
}

recur(135, 2)

console.log('Рекурсивных вызовов ', calls)