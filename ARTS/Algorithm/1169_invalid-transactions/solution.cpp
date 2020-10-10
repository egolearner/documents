struct Trans {
    char name[11];
    char city[11];
    int min;
    int amount;
    int index;
};
int cmp(const void* a1, const void *a2) {
    const Trans* t1 = (const Trans*)a1;
    const Trans* t2 = (const Trans*)a2;
    int name_cmp = strcmp(t1->name, t2->name);
    if (name_cmp) {
        return name_cmp;
    }
    return t1->min - t2->min;
}

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Trans> trans(transactions.size());
        for (size_t i = 0; i < transactions.size(); i++) {
            auto& t = trans[i];
            sscanf(transactions[i].c_str(), "%[^,],%d,%d,%s", t.name, &t.min, &t.amount, t.city);
            t.index = i;
        }
        qsort(&trans[0], trans.size(), sizeof(Trans), cmp);
        unordered_set<int> invalids;
        size_t tw_begin = 0;
        if (trans[tw_begin].amount>1000) {
            invalids.insert(trans[tw_begin].index);
        }

        for (size_t i = 1; i < trans.size(); i++) {
            if (trans[i].amount>1000) {
                invalids.insert(trans[i].index);
            }
            if (strcmp(trans[i].name, trans[tw_begin].name) == 0) {
                for (; tw_begin < i && trans[i].min-trans[tw_begin].min>60; tw_begin++) {
                }
                for (size_t j = tw_begin; j < i; j++) {
                    if (strcmp(trans[i].city, trans[j].city) != 0  && trans[i].min-trans[j].min <= 60) {
                        invalids.insert(trans[i].index);
                        invalids.insert(trans[j].index);
                    }
                }
            } else {
                tw_begin = i;
            }
        }
        vector<string> result;
        result.reserve(invalids.size());
        for (auto i : invalids) {
            result.push_back(transactions[i]);
        }
        return result;
    }
};

/* XXX
 * 比想象中复杂，主要是低级错误比较多，犯的错有
 * 1. sscanf没用[^,]
 * 2. 一开始排序的时候想基于name,city,time来排序，但是同city的多条记录可能把不同city间隔在60分钟内的记录隔开
 * 3. 后来改为基于name,time排序，但没有用时间窗口，只和前面一条比较，但是有可能前面的n条都和某一条冲突
 *
 * 效率方面：可以记录index，不需要再组装string
 * 
 * 看到比较机智的答案是直接sort string vector
 */
