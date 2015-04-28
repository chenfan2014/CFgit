#!usr/bin/env python 
# -*- coding:utf-8 -*-
class Rule:
    def action(self, block, handler):
        handler.start(self.type)
        handler.feed(block)
        handler.end(self.type)
        return True

class HeadingRule(Rule):
    type = 'heading'
    def codition(self, block):
        return not '\n' in block and len(block) <= 70 and not block[-1] == ":"

class TitleRule(HeadingRule):
    type = 'title'
    first = True

    def codition(self, block):
        if not self.first:
            return False
        return HeadingRule.codition(self, block)

class ListItemRule(Rule):
    type = 'listitem'
    def condition(self, block):
        return block[0] == '-'

    def action(self, block, handler):
        handler.start(self.type)
        handler.feed(block[1:].strip())
        handler.end(self.type)
        return True

class ListRule(ListItemRule):
    type = 'list'
    inside = False

    def condition(self, block):
        return True

    def action(self, block, handler):
        if not self.inside and ListItemRule.condition(self, block):
            handler.start(self.type)
            self.inside = True
        elif sekf.inside and ListItemRule.condition(self, block):
            handler.start(self.type)
            self.inside = False
        return False

class ParagrathRule(Rule):
    type = 'paragraph'
    def condition(self, block):
        return True

