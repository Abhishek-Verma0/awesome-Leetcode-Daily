
/**432. All O`one Data Structure
Hard
Topics
Companies

Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

    AllOne() Initializes the object of the data structure.
    inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
    dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
    getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
    getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".

Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"

 

Constraints:

    1 <= key.length <= 10
    key consists of lowercase English letters.
    It is guaranteed that for each call to dec, key is existing in the data structure.
    At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

 */

// DoubleLinkedList and Map
const dll = function(freq, ele, prev, next) {
    this.freq = freq;
    this.next = next?next:null;
    this.prev = prev?prev:null;
    this.ele = new Set();
    if(ele) {
        this.ele.add(ele)
    }
}
var AllOne = function() {
    this.nodeMap = new Map();
    this.head = null;
    this.tail = null;
};

/** 
 * @param {string} key
 * @return {void}
 */
AllOne.prototype.addtodll = function (key, node) {
    let temp;
    if(!node) {
        if(!this.head) {
            temp = new dll(1, key);
            this.head = temp;
            this.tail = temp;
        } else {
            if(this.head.freq === 1) {
                temp = this.head;
                this.head.ele.add(key);
            } else {
                temp = new dll(1, key, null, this.head);
                this.head.prev = temp;
                this.head = temp;
            }
        }
    } else {
        let c_node = node;
        let n_node = node.next;
        let n_freq = node.freq + 1;
        if(n_node === null) {
            temp = new dll(n_freq, key, c_node, null);
            this.tail = temp;
            c_node.next = temp;
        } else if (n_node.freq === n_freq){
            temp = n_node;
            temp.ele.add(key);
        } else {
            temp = new dll(n_freq, key, c_node, c_node.next);
            c_node.next = temp;
            temp.next.prev = temp;
        }

        c_node.ele.delete(key);
        if(c_node.ele.size === 0) {
            if(c_node.prev === null) {
                this.head = c_node.next;
                c_node.next.prev = null
            } else {
                c_node.prev.next = temp;
                temp.prev = c_node.prev;
            }
        }

    }
    return temp;
}
AllOne.prototype.inc = function(key) {
    let c_node = this.addtodll(key, this.nodeMap.get(key));
    this.nodeMap.set(key, c_node);
};

/** 
 * @param {string} key
 * @return {void}
 */
AllOne.prototype.removefromdll = function(key, node) {
    let c_freq = node.freq;
    let r_freq = c_freq - 1;
    let temp;
    if(c_freq === 1) {
        node.ele.delete(key);
        if(node.ele.size === 0) {
            if(this.head === this.tail) {
                this.head = null;
                this.tail = null;
            } else {
                this.head = node.next;
                node.next.prev = null;
            }
        }
        return null;
    } else {
        if(node.prev === null) {
            temp = new dll(r_freq, key, null, node);
            this.head = temp;
            node.prev = temp;
        } else if(node.prev.freq === r_freq) {
            temp = node.prev;
            temp.ele.add(key);
        } else {
            temp = new dll(r_freq, key, node.prev, node);
            node.prev.next = temp;
            node.prev = temp;
        }

        node.ele.delete(key);
        if(node.ele.size === 0) {
            if(node.next === null) {
                this.tail = node.prev;
                temp.next = null;
            } else {
                node.next.prev = temp;
                temp.next = node.next;
            }
        }
    }
    return temp;
}
AllOne.prototype.dec = function(key) {
    let c_node = this.removefromdll(key, this.nodeMap.get(key));
    if(c_node) {
        this.nodeMap.set(key, c_node);
    } else {
        this.nodeMap.delete(key)
    }
};

/**
 * @return {string}
 */
AllOne.prototype.getMaxKey = function() {
    if(this.tail) {
        const [f] = this.tail.ele;
        return f
    }
    return '';
};

/**
 * @return {string}
 */
AllOne.prototype.getMinKey = function() {
    if(this.head) {
        const [f] = this.head.ele;
        return f
    }
    return ''
};

/** 
 * Your AllOne object will be instantiated and called as such:
 * var obj = new AllOne()
 * obj.inc(key)
 * obj.dec(key)
 * var param_3 = obj.getMaxKey()
 * var param_4 = obj.getMinKey()
 */
