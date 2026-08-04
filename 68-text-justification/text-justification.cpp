class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> current_line;
        int current_length = 0;
        for (const string& word : words) {
            if (current_length + current_line.size() + word.length() > maxWidth) {
                result.push_back(justifyLine(current_line, current_length, maxWidth));
                current_line.clear();
                current_length = 0;
            }
            current_line.push_back(word);
            current_length += word.length();
        }
        string last_line = "";
        for (size_t i = 0; i < current_line.size(); ++i) {
            last_line += current_line[i];
            if (i < current_line.size() - 1) {
                last_line += " ";
            }
        }
        last_line += string(maxWidth - last_line.length(), ' ');
        result.push_back(last_line);

        return result;
    }

private:
    string justifyLine(const vector<string>& line, int current_length, int maxWidth) {
        if (line.size() == 1) {
            return line[0] + string(maxWidth - current_length, ' ');
        }

        int total_spaces = maxWidth - current_length;
        int gaps = line.size() - 1;

        int base_spaces = total_spaces / gaps;
        int extra_spaces = total_spaces % gaps;

        string justified_str = "";
        for (int i = 0; i < gaps; ++i) {
            justified_str += line[i];
            int spaces_to_add = base_spaces + (i < extra_spaces ? 1 : 0);
            justified_str += string(spaces_to_add, ' ');
        }
        justified_str += line.back();

        return justified_str;
    }
};