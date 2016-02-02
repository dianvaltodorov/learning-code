def verbose(original_function):
    # make a new function that prints a message when original_function starts and finishes
    def new_function(*args, **kwargs):
        print("Entering", original_function.__name__)
        original_function(*args, **kwargs)
        print("Exiting ", original_function.__name__)

    return new_function

@verbose
def widget_func():
    pass


widget_func()


def add_super_class_attributes(original_function):
    
    def new_function():
        return 


def create_decorator(n):
    def my_decorator(original_function):

        def new_function(bar):
            data = original_function(bar)
            data['new_key'] = n
            return data

        return new_function
    
    return my_decorator

@create_decorator(100)
def baby_function(foo):
    data = {}
    data['dido'] = 1
    return data

@create_decorator(200)
def baby_function2(foo)

print baby_function(101)

def clean_separators(value, separators=' -'):
    pass

import ipdb; ipdb.set_trace()
