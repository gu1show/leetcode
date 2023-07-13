// Link: https://leetcode.com/problems/course-schedule/description/
// Runtime: 16 ms
// Memory: 13.9 MB

class Solution 
{
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) 
    {
        std::vector<std::vector<int>> adjacentNodes(numCourses);
        for (const auto& connection : prerequisites)
            adjacentNodes[connection[1]].push_back(connection[0]);
        
        std::vector<bool> isVisited(numCourses), isInStack(numCourses);
        bool canFinishAllCourses = true;
        int i = 0;
        while ((i < numCourses) && (canFinishAllCourses))
        {
            if (dfs(i, adjacentNodes, isVisited, isInStack)) canFinishAllCourses = false;
            i++;
        }

        return canFinishAllCourses;
    }

private:
    bool dfs(int courseNumber, 
             const std::vector<std::vector<int>>& adjacentNodes, 
             std::vector<bool>& isVisited, 
             std::vector<bool>& isInStack)
    {
        if (isInStack[courseNumber]) return true;
        else if (isVisited[courseNumber]) return false;

        isInStack[courseNumber] = true;
        isVisited[courseNumber] = true;

        for (const auto& neighbour : adjacentNodes[courseNumber])
            if (dfs(neighbour, adjacentNodes, isVisited, isInStack))
                return true;
        
        isInStack[courseNumber] = false;

        return false;
    }
};