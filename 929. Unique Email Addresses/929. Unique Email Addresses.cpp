class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<pair<string, string>> hash;

        for (int i = 0; i < emails.size(); i++) {
            pair<string, string> unique;

            auto whereAt = emails[i].find('@');
            if (whereAt == string::npos) {
                cout << "No '@' found!" << endl;

                exit(1);
            }
            else {
                string localName = emails[i].substr(0, whereAt);        // [0, whereAt)
                string domainName = emails[i].substr(whereAt + 1);      // (whereAt, size)

                string uniqueLocalName = generateUniqueLocalName(localName);

                unique.first = uniqueLocalName;
                unique.second = domainName;

                hash.insert(unique);
            }
        }

        return hash.size();
    }

private:
    string generateUniqueLocalName(string oriStr) {
        string uniqueLocalName;

        string noPlusStr;
        auto wherePlus = oriStr.find('+');
        if (wherePlus != string::npos) {      // '+' found
            noPlusStr = oriStr.substr(0, wherePlus);
        }
        else {
            noPlusStr = oriStr;
        }

        uniqueLocalName = deleteDot(noPlusStr);

        return uniqueLocalName;
    }

    string deleteDot(string noPlusStr) {
        string uniqueLocalName = noPlusStr;

        while (true) {
            auto whereDot = uniqueLocalName.find('.');
            if (whereDot != string::npos) {
                auto dotItr = uniqueLocalName.begin() + whereDot;
                dotItr = uniqueLocalName.erase(dotItr);
            }
            else {
                break;
            }
        }

        return uniqueLocalName;
    }
};