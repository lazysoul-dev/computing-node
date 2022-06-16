const createVector = size => {
  const result = []

  for (let i = 0; i < size; i++) {
    result.push(i + 1)
  }

  return result
}

const createRandomVector = size => {
  const result = []

  for (let i = size; i > 0; i--) {
    result.push(i)
  }

  return result
}

const createMatrix = size => {
  const result = []

  for (let i = 0; i < size; i++) {
    const subarray = []

    for (let j = 0; j < size; j++) {
      subarray.push(j)
    }

    result.push(subarray)
  }

  return result
}

module.exports = {
  createVector,
  createRandomVector,
  createMatrix,
}
