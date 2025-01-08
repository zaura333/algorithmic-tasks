// 2825. Make String a Subsequence Using Cyclic Increments

function canMakeSubsequence(str1: string, str2: string): boolean {
    let j = 0;

    for (let i = 0; i < str1.length; i++) {
        const altStr1 = str1[i] === 'z'
            ? 'a'
            : String.fromCharCode(str1.charCodeAt(i) + 1);

        if (str1[i] === str2[j] || altStr1 === str2[j]) {
            if (j === str2.length - 1) return true;
            j++;
        } 
    }

    return false;
};
