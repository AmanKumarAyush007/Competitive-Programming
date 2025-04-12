submissionId = 1341091994

class BrowserHistory
{
public:
    vector<string> arr;
    int curr;

    BrowserHistory(string homepage)
    {
        curr = 0;
        arr.push_back(homepage);
    }

    void visit(string url)
    {
        int end = arr.size() - 1;
        while (end > curr)
        {
            arr.pop_back();
            end--;
        }
        curr++;
        arr.push_back(url);
    }

    string back(int steps)
    {
        curr = max(0, curr - steps);
        return arr[curr];
    }

    string forward(int steps)
    {
        int end = arr.size() - 1;
        curr = min(end, curr + steps);
        return arr[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */