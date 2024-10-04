/**2491. Divide Players Into Teams of Equal Skill
Medium
Topics
Companies
Hint

You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

 

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.

Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.

 

Constraints:

    2 <= skill.length <= 105
    skill.length is even.
    1 <= skill[i] <= 1000

 */


/**
 * @param {number[]} skill
 * @return {number}
 */
var dividePlayers = function(skill) {
    // Step 1: Sort the skill array
    skill.sort((a, b) => a - b);
    
    let totalSkill = skill[0] + skill[skill.length - 1]; // Required sum for each pair
    let chemistrySum = 0;

    // Step 2: Pair players using two pointers
    for (let i = 0; i < skill.length / 2; i++) {
        // Check if the sum of current pair matches the required totalSkill
        if (skill[i] + skill[skill.length - 1 - i] !== totalSkill) {
            return -1; // Invalid configuration, return -1
        }
        // Calculate the chemistry (product of pair) and add it to the sum
        chemistrySum += skill[i] * skill[skill.length - 1 - i];
    }

    return chemistrySum; // Return total chemistry
};
