// Link: https://leetcode.com/problems/my-calendar-i/
// Runtime: 166 ms
// Memory: 38.9 MB

class MyCalendar {
public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto it = calender.upper_bound(start);
    if ((it == calender.end()) || (it->second >= end)) {
      calender[end] = start;
      return true;
    } else
      return false;
  }

private:
  std::map<int, int> calender;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
