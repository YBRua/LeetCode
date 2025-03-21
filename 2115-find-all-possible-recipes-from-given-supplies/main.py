from typing import List


# 2115-find-all-possible-recipes-from-given-supplies
class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        has_update = True
        craftables = set()

        supplies_set = set(supplies)

        while has_update:
            has_update = False
            for recipe, ingredient in zip(recipes, ingredients):
                if all(ingred in supplies_set for ingred in ingredient):

                    if recipe not in craftables:
                        craftables.add(recipe)
                        supplies_set.add(recipe)
                        has_update = True

        return list(craftables)
