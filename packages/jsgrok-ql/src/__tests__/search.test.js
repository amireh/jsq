const { assert } = require('chai');
const { apply } = require('../')
const { createSpecimenTests } = require('./utils')

describe('jsgrok-ql::search', function() {
  createSpecimenTests('search')(specs => {
    specs.forEach(function({ spec = null, query: sourceQuery, source, matches: expectedMatches }) {
      it(spec || `applies ${sourceQuery}`, function() {
        const results = apply(sourceQuery, source);

        if (expectedMatches) {
          assert(!results.some(x => x.error === true))
          assert.equal(expectedMatches.length, results.length,
            `Expected ${expectedMatches.length} match(es), not ${results.length}`
          )

          expectedMatches.forEach((expected, index) => {
            const actual = results[index]

            if (expected.line) {
              assert.equal(expected.line, actual.line,
                `Expected match#${index} to be found on line ${expected.line} ` +
                `but was found on line ${actual.line}`
              )
            }
          })
        }
      });
    })
  })
});