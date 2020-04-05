/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

// Including criterion
#include <criterion/criterion.h>

// Including application's headers
#include "istl/observable.h"
#include "istl/private/p_observable.h"

/*!
 * An object which is an observer and an observable at the same time
 * */
struct TestSubject {
    observable_t *obs;
    int var;
};

int test_callback(void *obsr_p, void *obs_p, int sig)
{
    struct TestSubject *subj = obsr_p;
    struct TestSubject *obs = obs_p;

    if (obsr_p == NULL || obs_p == NULL)
        return (-1);
    if (sig == 2) {
        subj->var = obs->var + 3;
    }
    return (0);
}

Test(observable_basic, creating_an_observable)
{
    observable_t *obs = obs_create();
    mdata_t tmeta;

    cr_assert(obs->subscribers != NULL);
    cr_expect(list_len(obs->subscribers) == 0);
    tmeta = obs->subscribers->type_meta;
    cr_expect(tmeta.data_size == sizeof(observer_t));
    cr_expect(tmeta.copy == NULL);
    cr_expect(tmeta.destroy == NULL);
    obs_free(&obs);
}

Test(observable_subscribe, subscribe_mechanism)
{
    struct TestSubject subj = (struct TestSubject) {
        .obs = obs_create(),
        .var = 42
    };

    obs_subscribe(subj.obs, &subj, test_callback);
    cr_assert(list_len(subj.obs->subscribers) == 1);
    cr_assert(subj.var == 42);
    obs_notify(subj.obs, &subj, 0);
    cr_assert(subj.var == 42);
    obs_notify(subj.obs, &subj, 2);
    cr_assert(subj.var == 45);
}
