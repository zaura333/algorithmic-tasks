// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

function isPrefixOfWord(sentence: string, searchWord: string): number {
    const words: string[] = sentence.split(" ");

    for (let i = 0; i < words.length; i++) {
        if (words[i].startsWith(searchWord)) {
            return i + 1;
        }
    }

    return -1;
};
