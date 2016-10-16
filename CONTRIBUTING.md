## Cloning

This project may use submodules so in order to correctly clone them, please use:

    $ git clone --recursive git@github.com:vsl-lang/VSL.git

Now, perform your changes on a branch upon the `develop` branch:

    $ git checkout develop -b feature-your-feature-name

alternatively if you are submitting a fix:

    $ git checkout develop -b hotfix-your-hotfix-name

## Commiting

If you have [GPG commit signing](https://help.github.com/articles/signing-commits-using-gpg/) please sign off all your commits from that account. Additionally please sign off all commits with the `-s` flag. You can alias these `git co` using:

    $ git config alias.co 'commit -S -s'

## Submitting PRs

Submit all PRs to the `develop/` branch and they will be merged to master in the next release
