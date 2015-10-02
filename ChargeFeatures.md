#Additional Information about Charges
# Charge Features #

Charges can have additional information given about them, which may affect the way they
are displayed. I have chosen to call this additional information _features_, although
this is not a heraldic term it is useful for discussion purposes and is used in a
consistent fashion in the code.

# Specific Features #

Some features are only applicable to particular charges.
Examples of such features (shown in italics) include:

  * **A lion or _armed and langued gules_** which draws a yellow lion with red claws and tongue
  * **The sun _in his splendour_ or** which doesn't make any difference but sounds more splendid
  * **3 annulets _one inside the other_ or** which makes the annulets appear concentric rather than separate

These features are specific to each charge, i.e. _one inside the other_ will only be
recognised if it immediately follows **annulet**. For a complete list of charge specific
look at the [list of charges](ChargeList.md).

# General Charge Features #

There are a small number of features that are applicable to almost every charge. These are
as follows:

## demi ##

Any charge may be preceeded by the word **demi** in which case only half the charge will
be shown, typically animals show the top half, other charges show the dexter half.

## bundle ##

Any charge may be preceeded by the phrase **a bundle of** or **a pair of**. Bundle is assumed
to mean **3**, pair is assumed to mean **2**. In some cases this prefix will cause the
charges to actually be drawn in a bundle, for example **arrows** and **reeds**.

## dimidiated ##

There appear to be some examples of charges being described as **dimidiated**, with a
meaning similar to **demi**. I am investigating the exact syntax of this and will
implement it when I understand it!