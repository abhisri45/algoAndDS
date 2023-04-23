"""
After catching your classroom students cheating before, you realize your students are getting craftier and hiding words in 2D grids of letters. The word may start anywhere in the grid, and consecutive letters can be either immediately below or immediately to the right of the previous letter.

Given a grid and a word, write a function that returns the location of the word in the grid as a list of coordinates. If there are multiple matches, return any one.
"""
grid1 = [
	['c', 'c', 'x', 't', 'i', 'b'],
	['c', 'c', 'a', 't', 'n', 'i'],
	['a', 'c', 'n', 'n', 't', 't'],
	['t', 'c', 's', 'i', 'p', 't'],
	['a', 'o', 'o', 'o', 'a', 'a'],
	['o', 'a', 'a', 'a', 'o', 'o'],
	['k', 'a', 'i', 'c', 'k', 'i'],
]
word1 = "catnip"
word2 = "cccc"
word3 = "s"
word4 = "bit"
word5 = "aoi"
word6 = "ki"
word7 = "aaa"
word8 = "ooo"

grid2 = [['a']]
word9 = "a"

"""
find_word_location(grid1, word1) => [ (1, 1), (1, 2), (1, 3), (2, 3), (3, 3), (3, 4) ]
find_word_location(grid1, word2) =>
       [(0, 1), (1, 1), (2, 1), (3, 1)]
    OR [(0, 0), (1, 0), (1, 1), (2, 1)]
    OR [(0, 0), (0, 1), (1, 1), (2, 1)]
    OR [(1, 0), (1, 1), (2, 1), (3, 1)]
find_word_location(grid1, word3) => [(3, 2)]
find_word_location(grid1, word4) => [(0, 5), (1, 5), (2, 5)]
find_word_location(grid1, word5) => [(4, 5), (5, 5), (6, 5)]
find_word_location(grid1, word6) => [(6, 4), (6, 5)]
find_word_location(grid1, word7) => [(5, 1), (5, 2), (5, 3)]
find_word_location(grid1, word8) => [(4, 1), (4, 2), (4, 3)]
find_word_location(grid2, word9) => [(0, 0)]
"""

def checkWord(word, grid, row, col, rowColList):
    #print(word)
    if(len(word) == 0 ):
        return True
    if(len(word) == 1 and grid[row][col] == word[0]):
        #print(row, col)
        rowColList.append((row, col))
        return grid[row][col] == word[0]
    else:
        if grid[row][col] == word[0]:
            #print(row, col)
            rowColList.append((row, col))
            ret1= False
            ret2 = False
            if row+1 < len(grid1):
                ret1 = checkWord(word[1: len(word)], grid, row+1, col, rowColList)
            if not ret1 and col+1 < len(grid1[0]):
                ret2 = checkWord(word[1: len(word)], grid, row, col+1, rowColList)
            return ret1 or ret2
        else:
            return False

        return False

def func(grid, word):
    #print(word)
    for rowNum, row in enumerate(grid):
        for colNum, col in enumerate(row):
            wordMatch = False
            rowColList = list()
            if checkWord(word, grid, rowNum, colNum, rowColList):
                print(word)
                #print(rowColList)
                wordMatch = True
                break
        if wordMatch:
            break
            
    return rowColList
            
#print(len(grid1), len(grid1[0]))
print(func(grid1, word1))
print(func(grid1, word2))
print(func(grid1, word3))
