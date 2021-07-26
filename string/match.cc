/*
str1表示期望输入的字符串，str2为实际键盘输入的字符串，由于卡顿导致重复输入，现在确认str2是否为卡顿导致的错误

e.g. str1=word, str2=wwwworddd
返回: true

e.g. str1=word, str2=xord
返回：false
*/

bool recheck(string &t, int index, char prev) {
  for (int i = 0; i < index; ++i) {
    if (t[i] != prev)
      return false;
    }

  return true;
}

bool check(string &s, string &t) {
  if (s.size() > t.size()) return false;

  int i = 0, j = 0;
  char prev = s[i];
  while (i < s.size()) {
    while (j < t.size()) {
      if (s[i] == t[j]) {
	++j;
	break;
      } else if (prev != t[j]) {
	return false;
      }
      ++j;
    }
    prev = s[i];
    ++i;
   }

   if (i == s.size() && recheck(t, j, prev))
     return true;

   return false;
}
