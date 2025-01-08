// 1072. Flip Columns For Maximum Number of Equal Rows

interface BitsOccurences {
    [key: string]: number;
}

function maxEqualRowsAfterFlips(matrix: number[][]): number {
    if (!matrix.length) return 0;
  
    const occurences: BitsOccurences = {};
    
    const bitLength: number = matrix[0].join('').length;

    matrix.forEach(arr => {
        const pattern = arr[0] === 0
        ? arr.join('')
        : arr.map(bit => bit ^ 1).join("")

        if (!occurences[pattern]) {
            occurences[pattern] = 1;
        } else {
            occurences[pattern] += 1;
        }
    });

    const values = Object.values(occurences);

    return Math.max(...values);
};
