"""
Returns a namedtuple("name", "age") object.
Also returns dict('name', 'age') if arg `d` is True

Arguments:
name  – first name, must be string
age   – age of person, must be int
d     – to return Person as `dict` (default=False)

"""

class SampleClass:
    """Summary of class here.

    Longer class information...
    Longer class information...

    Attributes:
        likes_spam: A boolean indicating if we like SPAM or not.
        eggs: An integer count of the eggs we have laid.
    """

    def __init__(self, likes_spam: bool = False):
        """Initializes the instance based on spam preference.

        Args:
          likes_spam: Defines if instance exhibits this preference.
        """
        self.likes_spam = likes_spam
        self.eggs = 0

    @property
    def butter_sticks(self) -> int:
        """The number of butter sticks we have."""

class CheeseShopAddress:
      """The address of a cheese shop.

  ...
  """

class OutOfCheeseError(Exception):
  """No more cheese is available."""
  
with open("hello.txt") as hello_file:
    for line in hello_file:
        print(line)
