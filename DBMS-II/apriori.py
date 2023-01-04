def apriori(transactions, min_support):
    # Find unique items from input
    items = set()
    for t in transactions:
        for item in t:
            items.add(item)

    # Create a dictionary to store the support for each item
    supports = {}
    for item in items:
        support = 0
        for t in transactions:
            if item in t:
                support += 1
        supports[item] = support

    # Find items with support greater than or equal to the minimum support
    eligible_items = [item for item in items if supports[item] >= min_support]

    # Sort the items by support in decreasing order
    eligible_items.sort(key=lambda x: supports[x], reverse=True)

    item_sets = []
    # Iterate through the frequent items and create single-item sets
    for item in eligible_items:
        item_set = {item}
        item_sets.append(frozenset(item_set))

    # Iterate through the frequent item sets and try to extend them
    final_result = []
    k = 2
    while item_sets:
        # Generate item sets of greater length
        old_item_sets = item_sets
        item_sets = []
        candidate_item_sets = []
        for i in range(len(old_item_sets)):
            for j in range(i+1, len(old_item_sets)):
                # Check if the first k-2 items are the same
                items_i = list(old_item_sets[i])
                items_j = list(old_item_sets[j])
                if items_i[:k-2] == items_j[:k-2]:
                    # Create a new item set by combining the two sets
                    new_item = old_item_sets[i] | old_item_sets[j]
                    candidate_item_sets.append(new_item)

        # Calculate the support for each candidate item set
        supports = {}
        for item_set in candidate_item_sets:
            supports[item_set] = 0
            for t in transactions:
                if item_set.issubset(t):
                    supports[item_set] += 1

        # Keep only the item sets with support greater than or equal to the minimum support
        for item_set, count in supports.items():
            if count >= min_support:
                item_sets.append(item_set)

        final_result.append(item_sets)
        # Increment the item set size counter
        k += 1

    # Return the resulting frequent item sets
    return final_result