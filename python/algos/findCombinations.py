# Write a program to simulate the digitCharMap in mobile
# // # Following is the mapping for input keys.
# // # (1=abc, 2=def, 3=ghi, 4=jkl, 5=mno, 6=pqr, 7=stu, 8=vwx, 9=yz, 0=space)
# // # 
# // # If user presses 12, all combination letters should be printed, 
# // # eg ["ad","ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]


digitCharMap = {
    '1': 'abc',
    '2': 'def',
    '3': 'ghi',
    '4': 'jkl',
    '5': 'mno',
    '6': 'pqr',
    '7': 'stu',
    '8': 'vwx',
    '9': 'yz',
    '0': ' '
}


def simulate_digitCharMap(nums):
    if len(nums) == 1:
        return list(digitCharMap[nums[0]])
    prev_combinations = simulate_digitCharMap(nums[:-1])
    current_letters = digitCharMap[nums[-1]]
    return [combination + letter for combination in prev_combinations for letter in current_letters]

print(simulate_digitCharMap("029"))





