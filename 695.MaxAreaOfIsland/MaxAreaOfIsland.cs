using System;
using System.Collections.Generic;

public class Solution
{
    private int _nCols;
    private int _nRows;
    private bool _isRowValid(int row)
    {
        return row >= 0 && row < _nRows;
    }
    private bool _isColValid(int col)
    {
        return col >= 0 && col < _nCols;
    }
    private int _islandBFS(int[][] grid, (int Row, int Col) start)
    {
        int size = 0;
        var bfsQ = new Queue<(int Row, int Col)>();
        bfsQ.Enqueue(start);
        while (bfsQ.Count != 0)
        {
            var node = bfsQ.Dequeue();
            if (grid[node.Row][node.Col] == 1)
            {
                grid[node.Row][node.Col] = 0;
                size += 1;
            }
            else
            {
                continue;
            }
            if (_isRowValid(node.Row + 1) && grid[node.Row + 1][node.Col] == 1)
            {
                bfsQ.Enqueue((node.Row + 1, node.Col));
            }
            if (_isRowValid(node.Row - 1) && grid[node.Row - 1][node.Col] == 1)
            {
                bfsQ.Enqueue((node.Row - 1, node.Col));
            }
            if (_isColValid(node.Col + 1) && grid[node.Row][node.Col + 1] == 1)
            {
                bfsQ.Enqueue((node.Row, node.Col + 1));
            }
            if (_isColValid(node.Col - 1) && grid[node.Row][node.Col - 1] == 1)
            {
                bfsQ.Enqueue((node.Row, node.Col - 1));
            }
        }
        return size;
    }
    public int MaxAreaOfIsland(int[][] grid)
    {
        int maxArea = 0;
        _nRows = grid.Length;
        if (_nRows == 0)
        {
            return 0;
        }
        _nCols = grid[0].Length;
        for (int i = 0; i < _nRows; ++i)
        {
            for (int j = 0; j < _nCols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int area = _islandBFS(grid, (i, j));
                    maxArea = Math.Max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
}
