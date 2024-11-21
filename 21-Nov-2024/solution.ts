// 2257. Count Unguarded Cells in the Grid

function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    const wallSet: Set<string> = new Set(walls.map(wall => wall.join(",")));
    const guardSet = new Set<string>(guards.map(guard => guard.join(",")));
    const guarded = new Set<string>();

    for (let g of guards) {
        let x = g[0];
        let y = g[1];

        x = g[0] + 1;
        while (x < m && !wallSet.has(`${x},${y}`) && !guardSet.has(`${x},${y}`)) {
            guarded.add(`${x},${y}`);
            x++;
        }

        x = g[0] - 1;
        while (x >= 0 && !wallSet.has(`${x},${y}`) && !guardSet.has(`${x},${y}`)) {
            guarded.add(`${x},${y}`);
            x--;
        }

        x = g[0];
        y = g[1] + 1;
        while (y < n && !wallSet.has(`${x},${y}`) && !guardSet.has(`${x},${y}`)) {
            guarded.add(`${x},${y}`);
            y++;
        }

        y = g[1] - 1;
        while (y >= 0 && !wallSet.has(`${x},${y}`) && !guardSet.has(`${x},${y}`)) {
            guarded.add(`${x},${y}`);
            y--;
        }
    }

    return m * n - guarded.size - wallSet.size - guardSet.size;
}
