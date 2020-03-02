shop = input()
need = input()

shop_map, need_map = {}, {}

for c in shop:
    if shop_map.get(c):
        shop_map[c] += 1
    else:
        shop_map[c] = 1

for c in need:
    if need_map.get(c):
        need_map[c] += 1
    else:
        need_map[c] = 1

dif = 0
for cor,cnt in need_map.items():
    if shop_map.get(cor):
        if shop_map[cor] < cnt:
            dif += cnt-shop_map[cor]
    else:
        dif += cnt
if dif>0:
    print("No {}".format(dif))
else:
    print("Yes {}".format(len(shop)-len(need)))