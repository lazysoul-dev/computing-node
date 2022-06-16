const ComputingNode = require('bindings')('ComputingNode')
const SegfaultHandler = require('segfault-handler')
SegfaultHandler.registerHandler('crash.log')
module.exports = ComputingNode
