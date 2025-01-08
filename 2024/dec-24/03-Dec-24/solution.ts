// 2109. Adding Spaces to a String

function addSpaces(s: string, spaces: number[]): string {
    let result: string = "";
    let currStart: number = 0;

    for (const space of spaces) {
        result += s.substring(currStart, space) + " ";
        currStart = space;
    }

    result += s.substring(currStart);

    return result;
};
