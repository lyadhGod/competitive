size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.size();
  return s.substr(start, last - start);