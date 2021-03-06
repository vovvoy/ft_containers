/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skybt <skybt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:32:59 by skybt             #+#    #+#             */
/*   Updated: 2020/08/08 12:39:24 by skybt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Test.hpp"

static void test_simple_insert()
{
    ft::set<int> set;

    set.insert(0);
    assert(set.size() == 1);
    set.insert(1);
    assert(set.size() == 2);
    set.insert(1);
    assert(set.size() == 2);

    for (size_t l = 0; l < 50; l++)
        set.insert(l);

    assert(set.size() == 50);
}

static void test_accessors()
{
    ft::set<int> set;

    assert(set.empty());
    assert(set.size() == 0);
    set.insert(0);
    assert(!set.empty());
    assert(set.size() == 1);
    set.insert(1);
    assert(set.size() == 2);
    set.insert(1);
    assert(set.size() == 2);

    for (size_t l = 0; l < 50; l++)
        set.insert(l);

    assert(set.count(0));
    assert(set.count(1));
    assert(set.count(2));
    assert(set.count(3));
    assert(set.count(4));
    assert(set.count(49));
    assert(!set.empty());

    set.clear();
    assert(set.empty());
    assert(set.size() == 0);
    set.insert(0);
    assert(!set.empty());
    assert(set.size() == 1);
    set.insert(1);
    assert(set.size() == 2);
    set.insert(1);
    assert(set.size() == 2);

    assert(!set.empty());
}

static void test_index()
{
    ft::set<int> set;

    assert(set.empty());
    assert(set.size() == 0);
    set.insert(0);
    assert(set.count(0));
    assert(!set.empty());
    assert(set.size() == 1);
    set.insert(1);
    assert(set.count(1));
    assert(set.size() == 2);
    set.insert(1);
    assert(set.count(1));
    assert(set.size() == 2);

    for (size_t l = 0; l < 50; l++)
        set.insert(l);

    assert(set.count(0));
    assert(set.count(1));
    assert(set.count(2));
    assert(set.count(3));
    assert(set.count(4));
    assert(set.count(49));
    assert(!set.empty());

    set.clear();
    assert(set.empty());
    assert(set.size() == 0);
    set.insert(0);
    assert(!set.empty());
    assert(set.size() == 1);
    set.insert(1);
    assert(set.size() == 2);
    set.insert(1);
    assert(set.size() == 2);

    assert(!set.empty());
}

static void test_constructors()
{
    ft::set<int> set;
    set.insert(0);
    set.insert(90);
    set.insert(2);

    assert(set.size() == 3);

    ft::set<int> cpy;
    assert(cpy.size() == 0);

    cpy = set;
    assert(cpy.size() == 3);
    cpy.insert(0);
    cpy.insert(90);
    cpy.insert(2);

    cpy.insert(5);
    set.insert(5);
    set.insert(9);
    assert(cpy.count(5));
    assert(set.count(5));

    swap(cpy, set);
    assert(set.count(5));
    assert(cpy.count(5));

    assert(set.size() == 4);
    assert(cpy.size() == 5);

    ft::set<int> cpy2(cpy);

    assert(cpy2.size() == 5);
    assert(cpy.count(5));
    assert(cpy2.count(5));
}

static void test_iterators()
{
    ft::set<int> set;
    set.insert(0);
    set.insert(90);
    set.insert(2);

    ft::set<int>::iterator ite = set.begin();
    assert(*(ite++) == 0);
    assert(*ite == 2);
    assert(*(++ite) == 90);

    assert(++ite == set.end());
    assert(--ite != set.end());

    const ft::set<int> &set2 = set;

    ft::set<int>::const_iterator ite2 = set2.end();
    --ite2;

    assert(*(ite2--) == 90);
    assert(*ite2 == 2);
    assert(*(--ite2) == 0);

    assert(ite2 == set2.begin());
}

static void test_reverse_iterators()
{
    ft::set<int> set;
    set.insert(0);
    set.insert(90);
    set.insert(2);

    ft::set<int>::reverse_iterator ite = set.rbegin();
    assert(*(ite++) == 90);
    assert(*ite == 2);
    assert(*(++ite) == 0);

    assert(++ite == set.rend());
    assert(--ite != set.rend());

    const ft::set<int> &set2 = set;

    ft::set<int>::const_reverse_iterator ite2 = set2.rend();
    --ite2;

    assert(*(ite2--) == 0);
    assert(*ite2 == 2);
    assert(*(--ite2) == 90);

    assert(ite2 == set2.rbegin());
}

static void test_insert()
{
    ft::set<int> set;
    set.insert(0);
    set.insert(90);
    set.insert(2);

    int tab[6] = {
        0,
        50,
        6,
        -45,
        4,
        6,
    };

    set.insert(tab, tab + 6);
    assert(set.size() == 7);
    assert(set.count(0));
    assert(set.count(90));
    assert(set.count(6));
    assert(set.count(-45));
    assert(set.count(4));

    set.clear();
    set.insert(tab, tab + 6);
    assert(set.size() == 5);
    assert(set.count(0));
    assert(set.count(6));
    assert(set.count(-45));
    assert(set.count(4));
}

static void test_cmp()
{
    ft::set<int> set;
    set.insert(0);
    set.insert(90);

    ft::set<int> set2;
    set2.insert(0);
    set2.insert(90);
    set2.insert(2);

    assert(set != set2);
    assert(set2 < set);
    assert(set2 <= set);
    assert(!(set2 > set));
    assert(!(set2 >= set));

    set.insert(2);
    assert(set == set2);
    assert(!(set2 < set));
    assert(set2 <= set);
    assert(!(set2 > set));
    assert(set2 >= set);

    set.insert(1);
    assert(set != set2);
    assert(set2 > set);
    assert(set2 >= set);
    assert(!(set2 < set));
    assert(!(set2 <= set));
}

static void test_swap()
{
    ft::set<int> set;
    set.insert(10);
    set.insert(36);
    set.insert(8);

    ft::set<int> set2;
    set2.insert(0);
    set2.insert(90);

    assert(set.size() == 3);
    assert(set.count(10));
    assert(set.count(36));
    assert(set.count(8));
    assert(set2.size() == 2);
    assert(set2.count(0));
    assert(set2.count(90));

    swap(set, set2);

    assert(set2.size() == 3);
    assert(set2.count(10));
    assert(set2.count(36));
    assert(set2.count(8));
    assert(set.size() == 2);
    assert(set.count(0));
    assert(set.count(90));

    set2.swap(set);

    assert(set.size() == 3);
    assert(set.count(10));
    assert(set.count(36));
    assert(set.count(8));
    assert(set2.size() == 2);
    assert(set2.count(0));
    assert(set2.count(90));
}

static void test_count_find()
{
    ft::set<int> set;
    set.insert(10);
    set.insert(36);
    set.insert(8);

    assert(*set.find(10) == 10);
    assert(*set.find(36) == 36);
    assert(set.find(99) == set.end());
    assert(set.find(0) == set.end());
    assert(set.find(8) == set.begin());

    assert(set.count(10) == 1);
    assert(set.count(9) == 0);
    assert(set.count(36) == 1);
    assert(set.count(55) == 0);
}

static void test_range()
{
    ft::set<int> set;
    set.insert(10);
    set.insert(36);
    set.insert(8);

    ft::set<int>::iterator ite = set.begin();
    ++ite;

    assert(set.lower_bound(5) == set.begin());
    assert(set.lower_bound(9) != set.begin());
    assert(set.lower_bound(9) == ite);
    assert(set.lower_bound(60) == set.end());
    ++ite;

    assert(set.lower_bound(35) == ite);
    assert(set.lower_bound(36) == ite);
    assert(set.lower_bound(37) != ite);
    ++ite;
    assert(set.lower_bound(37) == ite);
    assert(set.lower_bound(37) == set.end());

    ite = set.begin();

    assert(set.upper_bound(5) == ite);
    assert(set.upper_bound(6) == ite);
    assert(set.upper_bound(8) != ite);
    ++ite;
    assert(set.upper_bound(8) == ite);
    assert(set.upper_bound(9) == ite);
    assert(set.upper_bound(10) != ite);
    ++ite;
    assert(set.upper_bound(10) == ite);
    assert(set.upper_bound(30) == ite);

    typedef ft::set<int>::iterator iter;
    ft::pair<iter, iter> range;

    range = set.equal_range(8);
    ite = set.begin();
    assert(range.first == set.begin() && range.second == ++ite);

    range = set.equal_range(36);
    ite = set.begin();
    ++ite;
    assert(range.first == ++ite && range.second == ++ite);

    range = set.equal_range(50);
    assert(range.first == set.end());
    assert(range.second == set.end());

    range = set.equal_range(0);
    assert(range.first == set.begin());
    assert(range.second == set.begin());
}

void test_set()
{
    test_one("simple_insert", test_simple_insert);
    test_one("accessors", test_accessors);
    test_one("index", test_index);
    test_one("constructors", test_constructors);
    test_one("iterators", test_iterators);
    test_one("reverse_iterators", test_reverse_iterators);
    test_one("insert", test_insert);
    test_one("cmp", test_cmp);
    test_one("swap", test_swap);
    test_one("count_find", test_count_find);
    test_one("range", test_range);
}
