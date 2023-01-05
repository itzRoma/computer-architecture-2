#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/ktime.h>
#include <linux/slab.h>

MODULE_AUTHOR("Bondarenko Roman from IO-03");
MODULE_DESCRIPTION("Laboratory work #7");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int prints_num = 1;

module_param(prints_num, uint, S_IRUGO);

MODULE_PARM_DESC(prints_num, "How many times 'Hello, World!' string will be printed");

struct event_list {
    struct list_head list;
    ktime_t event_time;
};

static struct list_head event_list_head;

static LIST_HEAD(event_list_head);

void new_event(int);

static int __init hello_init(void)
{
    if (prints_num == 0) {
        printk(KERN_WARNING "WARNING: parameter is 0");  
    }
    
    if (prints_num >= 5 && prints_num <= 10) {
    	printk(KERN_WARNING "WARNING: parameter is between 5 and 10");
    }

    // if (prints_num > 10) {
    //     printk(KERN_ERR "ERROR: parameter is too large, should be less than 10");
    //     return -EINVAL;
    // }

    BUG_ON(prints_num > 10);
  
    int i;
    for (i = 0; i < prints_num; i++) {
        printk(KERN_EMERG "Hello, World!\n");
        new_event(i);
    }
    return 0;
}

static void __exit hello_exit(void) {
  struct event_list *md, *tmp;
  list_for_each_entry_safe(md, tmp, &event_list_head, list) {
    printk(KERN_EMERG "Time: %lld\n", md->event_time);
    list_del(&md->list);
    kfree(md);
  }
}

void new_event(int i) {
    struct event_list *element = NULL;
    element = kmalloc(sizeof(struct event_list), GFP_KERNEL);

    BUG_ON(i == 7);

    element->event_time = ktime_get();
    list_add_tail(&element->list, &event_list_head);
}

module_init(hello_init);
module_exit(hello_exit);
