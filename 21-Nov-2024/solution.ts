function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    const wallStrings: string[] = walls.map(wall => wall.join(""));
    const guarded = new Set<string>(wallStrings);

    for (let g of guards) {
        let x = g[0];
        let y = g[1];

        while (x < m && wallStrings.indexOf(`${x}${y}`) === -1) {
            guarded.add(`${x}${y}`);
            x++;
        }

        x = g[0];

        while (x >= 0 && wallStrings.indexOf(`${x}${y}`) === -1) {
            guarded.add(`${x}${y}`);
            x--;
        }

        x = g[0];

        while (y < n && wallStrings.indexOf(`${x}${y}`) === -1) {
            guarded.add(`${x}${y}`);
            y++;
        }

        y = g[1];

        while (y >= 0 && wallStrings.indexOf(`${x}${y}`) === -1) {
            guarded.add(`${x}${y}`);
            y--;
        }
    }

    return m*n - guarded.size;
};
