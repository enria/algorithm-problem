sort(list, list + n, [](Grade s1, Grade s2) { return s1.m > s2.m; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[1] = i + 1;
    }

    sort(list, list + n, [](Grade s1, Grade s2) { return s1.e > s2.e; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[2] = i + 1;
    }

    sort(list, list + n,
         [](Grade s1, Grade s2) { return s1.average > s2.average; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[3] = i + 1;
    