class LockingTree(object):
    # [-1, 0, 0, 1, 1, 2, 2]
    def __init__(self, parent):
        """
        :type parent: List[int]
        """
        self.parent = parent
        self.childs = { }
        for i,j  in enumerate(parent):
            if j != -1:
                if j not in self.childs:
                    self.childs[j] = [i]
                else:
                    self.childs[j].append(i)
        self.locked =[-1 for i in parent]
        # print(self.locked, self.childs)

    def lock(self, num, user):
        """
        :type num: int
        :type user: int
        :rtype: bool
        """
        if self.locked[num] == -1:
            self.locked[num] = user
            return True
        return False
        

    def unlock(self, num, user):
        """
        :type num: int
        :type user: int
        :rtype: bool
        """
        if self.locked[num] == user:
            self.locked[num] = -1
            return True
        return False

    def upgrade(self, num, user):
        """
        :type num: int
        :type user: int
        :rtype: bool
        """
        if self.locked[num] != -1:
            return False

        lockable = self.get_locked_childs(num)
        loc_parents  = self.get_locked_parents(num)
        # print(lockable)
        if lockable and not loc_parents:
            for item in lockable:
                if self.locked[item] != -1:
                    self.locked[item] = -1
            self.locked[num] = user
            return True
        else:
            return False

    def get_locked_childs(self, root, lockable = set()):
        # print("get for ", root)
        if root in self.childs:
            for item in self.childs[root]:
                if self.locked[item] != -1:
                    lockable.add(item)
                lockable.intersection(self.get_locked_childs(item))
        # print("return get for ", root, lockable)
        return lockable

    def get_locked_parents(self, root, lockable = set()):
        curr = root
        while curr != -1:
            if self.locked[self.parent[curr]] != -1:
                lockable.add(self.parent[curr])
            curr = self.parent[curr]
        return lockable
parent = [-1, 0, 0, 1, 1, 2, 2]
# [null,false,false,false,true,false]
obj = LockingTree(parent)
print(obj.lock(2,2))
print( obj.locked, obj.childs)
print(obj.unlock(2,3))
print( obj.locked, obj.childs)
print(obj.unlock(2,2))
print( obj.locked, obj.childs)
print(obj.lock(4,5))
print( obj.locked, obj.childs)
print(obj.upgrade(0,1))
print( obj.locked, obj.childs)
print(obj.lock(0,1))
print( obj.locked, obj.childs)
