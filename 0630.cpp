// Link: https://leetcode.com/problems/course-schedule-iii/
// Runtime: 332 ms
// Memory: 63.5 MB

class Solution 
{
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) 
    {
        std::sort(courses.begin(), courses.end(), 
                  [](const std::vector<int>&a, const std::vector<int>&b)
                  {return a[1] < b[1];});
        
        priority_queue<int> priority;
        int sum = 0;
        for (auto element : courses)
        {
            sum += element[0];
            priority.push(element[0]);
            if (sum > element[1])
            {
                sum -= priority.top();
                priority.pop();
            }
        }
        
        return priority.size();
    }
};
